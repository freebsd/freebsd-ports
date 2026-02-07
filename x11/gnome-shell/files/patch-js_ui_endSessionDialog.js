--- js/ui/endSessionDialog.js.orig	2025-04-13 15:04:25 UTC
+++ js/ui/endSessionDialog.js
@@ -233,8 +233,6 @@ class EndSessionDialog extends ModalDialog.ModalDialog
         });
 
         this._loginManager = LoginManager.getLoginManager();
-        this._canRebootToBootLoaderMenu = false;
-        this._getCanRebootToBootLoaderMenu().catch(logError);
 
         this._userManager = AccountsService.UserManager.get_default();
         this._user = this._userManager.get_user(GLib.get_user_name());
@@ -452,24 +450,6 @@ class EndSessionDialog extends ModalDialog.ModalDialog
                 },
                 label,
             });
-
-            // Add Alt "Boot Options" option to the Reboot button
-            if (this._canRebootToBootLoaderMenu && signal === 'ConfirmedReboot') {
-                this._rebootButton = button;
-                this._rebootButtonAlt = this.addButton({
-                    action: () => {
-                        this.close(true);
-                        let signalId = this.connect('closed', () => {
-                            this.disconnect(signalId);
-                            this._confirmRebootToBootLoaderMenu();
-                        });
-                    },
-                    label: C_('button', 'Boot Options'),
-                });
-                this._rebootButtonAlt.visible = false;
-                this._capturedEventId = this.connect('captured-event',
-                    this._onCapturedEvent.bind(this));
-            }
         }
     }
 
