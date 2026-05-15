--- backend/libinput/switch.c.orig	2022-02-03 13:19:54.000000000 -0800
+++ backend/libinput/switch.c	2026-04-08 15:45:12.489184000 -0700
@@ -40,6 +40,8 @@ void handle_switch_toggle(struct libinput_event *event
 	case LIBINPUT_SWITCH_TABLET_MODE:
 		wlr_event.switch_type = WLR_SWITCH_TYPE_TABLET_MODE;
 		break;
+	case LIBINPUT_SWITCH_KEYPAD_SLIDE:
+		return;
 	}
 	switch (libinput_event_switch_get_switch_state(sevent)) {
 	case LIBINPUT_SWITCH_STATE_OFF:
