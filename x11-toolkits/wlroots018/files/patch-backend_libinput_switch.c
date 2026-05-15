https://gitlab.freedesktop.org/wlroots/wlroots/-/commit/c1452d881147

--- backend/libinput/switch.c.orig	2025-10-23 10:00:25 UTC
+++ backend/libinput/switch.c
@@ -36,6 +36,8 @@ void handle_switch_toggle(struct libinput_event *event
 	case LIBINPUT_SWITCH_TABLET_MODE:
 		wlr_event.switch_type = WLR_SWITCH_TYPE_TABLET_MODE;
 		break;
+	case LIBINPUT_SWITCH_KEYPAD_SLIDE:
+		return;
 	}
 	switch (libinput_event_switch_get_switch_state(sevent)) {
 	case LIBINPUT_SWITCH_STATE_OFF:
