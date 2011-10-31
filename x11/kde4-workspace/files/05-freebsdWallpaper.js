var activitiesList = activities();
for (var i in activitiesList) {
  var activity = activitiesList[i];
  activity.wallpaperPlugin = "image";
  activity.wallpaperMode = "SingleImage";
  activity.currentConfigGroup = new Array("Wallpaper", "image");
  activity.writeConfig("wallpaper", "stripes-freebsd-blue");
}
