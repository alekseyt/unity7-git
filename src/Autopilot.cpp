// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alex Launi <alex.launi@gmail.com>
 */

TestArgs  *running_test_args [32];
nux::TimerFunctor *test_expiration_functor;

void
TestFinished (TestArgs *args)
{
  GError *error = NULL;
  GVariant *result = g_variant_new ("(sb)", args->name, args->passed);

  g_dbus_connection_emit_signal (self->GetDBusConnection (),
                                 "com.canonical.Unity.Autopilot",
                                 "/com/canonical/Unity/Debug",
                                 "com.canonical.Unity.Autopilot",
                                 "TestFinished",
                                 result,
                                 &error);
  g_variant_unref (result);

  if (error != NULL)
  {
    g_warning ("An error was encountered emitting TestFinished signal");
    g_error_free (error);
  }

  self->running_tests--;

  if (self->running_tests == 0)
  {
    delete test_expiration_functor;

    self->GetCompisiteScreen ()->preparePaintSetEnabled (args->autopilot, false);
    self->GetCompositeScreen ()->donePaintSetEnabled (args->autopilot, false);
    CompositeScreenInterface::setHandler (args->autopilot->GetCompositeScreen (), false);
  }

  g_free (args->name);
  g_free (args);
}

void
on_tooltip_shown (GVariant *payload, TestArgs *arg)
{
  nux::GetTimer ().RemoveTimerHandler (arg->expiration_handler);
  ubus_server_unregister_interest (self->GetUBusConnection (), arg->ubus_handle);
  arg->passed = TRUE;
  TestFinished (arg);
}

Autopilot::Autopilot (CompScreen *screen, GDBusConnection *connection) :
  PluginClassHandler <Autopilot, CompScreen> (screen),
  _cscreen (CompositeScreen::get (screen)),
  _fps (0),
  _ctime (0),
  _frames (0)
{
  _dbus = connection;
  _ubus = ubus_server_get_default ();
  _cscreen->preparePaintSetEnabled (this, false);
  _cscreen->donePaintSetEnabled (this, false);

}

void
Autopilot::preparePaint (int msSinceLastPaint)
{
  int timediff;
  float ratio = 0.05;
  struct timeval now;
  
  gettimeofday (&now, 0);
  timediff = TIMEVALDIFF (&now, &_last_redraw);

  _fps = (_fps * (1.0 - ratio)) + (1000000.0 / TIMEVALDIFFU (&now, &_last_redraw) * ratio);
  _last_redraw = now;

  _frames++;
  _ctime += timediff;

  if (1)
  {
    g_debug ("updating fps: %.3f", _frames / (_ctime / 1000.0));
    _disp_fps = _frames / (_ctime / 1000.0);
    /*g_debug ("%0.0f frames in %.1f seconds = %.3f FPS",
             _frames, _ctime / 1000.0,
             _frames / (_ctime / 1000.0));*/

    /* reset frames and time after display */
    _frames = 0;
    _ctime = 0;
  }
  
  _cscreen->preparePaint (_alpha > 0.0 ? timediff : msSinceLastPaint);
  _alpha += timediff / 1000;
  _alpha = MIN (1.0, MAX (0.0, _alpha));
}

void
Autopilot::donePaint ()
{
  _cscreen->donePaint ();
}

GDBusConnection*
Autopilot::GetDBusConnection ()
{
  return _dbus;
}

UBusServer*
Autopilot::GetUBusConnection ()
{
  return _ubus;
}

CompositeScreen*
Autopilot::GetCompositeScreen ()
{
  return _cscreen;
}

void 
Autopilot::StartTest (const gchar *name)
{
  running_test_args[running_tests] = (TestArgs*) g_malloc (sizeof (TestArgs));
  TestArgs *arg = running_test_args[running_tests];
  if (arg == NULL) {
    g_error ("Failed to allocate memory for TestArgs");
    return;
  }

  if (running_tests == 0)
  {
    test_expiration_functor = new nux::TimerFunctor ();
    test_expiration_functor->OnTimerExpired.connect (sigc::ptr_fun (&TestFinished));
  }

  arg->name = g_strdup0 (name);
  arg->passed = FALSE;
  arg->autopilot = this;
  arg->expiration_handler = nux::GetTimer ().AddTimerHandler (TEST_TIMEOUT, test_expiration_functor, arg);  

  if (g_strcmp0 (name, "show_tooltip") == 0) 
  {
    TestTooltip (arg);
  }
  else if (g_strcmp0 (name, "show_quicklist") == 0)
  {
    TestQuicklist ();
  }
  else if (g_strcmp0 (name, "drag_launcher") == 0)
  {
    TestDragLauncher ();
  }
  else if (g_strcmp0 (name, "drag_launcher_icon_along_edge_drop") == 0)
  {
    TestDragLauncherIconAlongEdgeDrop ();
  }
  else if (g_strcmp0 (name, "drag_launcher_icon_out_and_drop") == 0)
  {
    TestDragLauncherIconOutAndDrop ();
  }
  else if (g_strcmp0 (name, "drag_launcher_icon_out_and_move") == 0)
  {
    TestDragLauncherIconOutAndMove ();
  }
  else
  {
    /* Clean up the arg we set up. Test does not exist */
    nux::GetTimer ().RemoveTimerHandler (arg->expiration_handler);
    g_free (arg->name);
    g_free (arg);

    return;
  }

  running_tests++;

  /* enable fps counting hooks */
  _cscreen->preparePaintSetEnabled (this, true);
  _cscreen->donePaintSetEnabled (this, true);
  CompositeScreenInterface::setHandler (_cscreen, true);
}

void
Autopilot::TestTooltip (TestArgs *arg)
{
  arg->ubus_handle = ubus_server_register_interest (_ubus,
                                                    UBUS_LAUNCHER_TOOLTIP_SHOWN,
                                                    (UBusCallback) on_tooltip_shown,
                                                    arg);
}

void
Autopilot::TestQuicklist ()
{
}

void
Autopilot::TestDragLauncher ()
{
}

void
Autopilot::TestDragLauncherIconAlongEdgeDrop ()
{
}

void
Autopilot::TestDragLauncherIconOutAndDrop ()
{
}

void
Autopilot::TestDragLauncherIconOutAndMove ()
{
}
