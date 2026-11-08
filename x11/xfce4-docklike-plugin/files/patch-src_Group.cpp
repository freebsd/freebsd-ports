--- src/Group.cpp.orig	2026-03-02 12:11:41 UTC
+++ src/Group.cpp
@@ -21,6 +21,22 @@ static GtkTargetList* targetList = gtk_target_list_new
 static GtkTargetEntry entries[1] = {{(gchar*)"application/docklike_group", 0, 0}};
 static GtkTargetList* targetList = gtk_target_list_new(entries, 1);
 
+static std::string getDragId(const std::shared_ptr<AppInfo>& appInfo)
+{
+	if (appInfo->mId.empty())
+		return "name:" + appInfo->mName;
+
+	return "id:" + appInfo->mId;
+}
+
+static std::shared_ptr<Group> getDragGroup(const std::string& dragId)
+{
+	return Dock::mGroups.findIf(
+		[&dragId](std::pair<const std::shared_ptr<AppInfo>, std::shared_ptr<Group>> group) -> bool {
+			return getDragId(group.first) == dragId;
+		});
+}
+
 Group::Group(std::shared_ptr<AppInfo> appInfo, bool pinned) : mGroupMenu(this)
 {
 	mIconPixbuf = nullptr;
@@ -1041,12 +1057,25 @@ void Group::onDragDataGet(const GdkDragContext* contex
 
 void Group::onDragDataGet(const GdkDragContext* context, GtkSelectionData* selectionData, guint info, guint time)
 {
-	gtk_selection_data_set(selectionData, gdk_atom_intern("button", false), 32, (const guchar*)this, sizeof(gpointer) * 32);
+	std::string dragId = getDragId(mAppInfo);
+	gtk_selection_data_set(selectionData, gtk_selection_data_get_target(selectionData), 8,
+		(const guchar*)dragId.data(), static_cast<gint>(dragId.size()));
 }
 
 void Group::onDragDataReceived(const GdkDragContext* context, int x, int y, const GtkSelectionData* selectionData, guint info, guint time)
 {
-	Dock::moveButton((Group*)(gpointer)gtk_selection_data_get_data(selectionData), this);
+	const guchar* data = gtk_selection_data_get_data(selectionData);
+	int length = gtk_selection_data_get_length(selectionData);
+
+	if (data == nullptr || length <= 0 || gtk_selection_data_get_format(selectionData) != 8
+		|| gtk_selection_data_get_data_type(selectionData) != gtk_selection_data_get_target(selectionData))
+		return;
+
+	std::string dragId((const char*)data, length);
+	std::shared_ptr<Group> moving = getDragGroup(dragId);
+
+	if (moving)
+		Dock::moveButton(moving.get(), this);
 }
 
 void Group::onDragBegin(GdkDragContext* context)
