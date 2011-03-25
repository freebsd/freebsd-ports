--- ksysguard~/gui/SensorDisplayLib/ListView.h	2011-02-18 12:44:19.000000000 +0200
+++ ksysguard/gui/SensorDisplayLib/ListView.h	2011-02-18 12:47:59.000000000 +0200
@@ -29,6 +29,41 @@
 class ListViewSettings;
 class QTreeView;
 
+class ListViewModel : public QStandardItemModel {
+public:
+	ListViewModel(QObject * parent = 0 ) : QStandardItemModel(parent)
+	{
+	}
+
+	ListViewModel(int rows, int columns, QObject * parent = 0) : QStandardItemModel(rows, columns, parent)
+	{
+	}
+
+	void addColumnAlignment( Qt::AlignmentFlag align )
+	{
+		mAlignment.append(align);
+	}
+
+	void clear()
+	{
+		QStandardItemModel::clear();
+		mAlignment.clear();
+	}
+
+	QVariant data(const QModelIndex &index, int role) const
+	{
+		int column = index.column();
+
+		if ( role == Qt::TextAlignmentRole && column >= 0 && column < mAlignment.size() )
+			return mAlignment[column];
+		else
+			return QStandardItemModel::data(index, role);
+	}
+
+private:
+	QList<Qt::AlignmentFlag> mAlignment;
+};
+
 class ListView : public KSGRD::SensorDisplay
 {
 	Q_OBJECT
@@ -61,9 +96,9 @@
 
 private:
 
-	typedef enum { Text, Int, Float, Time, DiskStat } ColumnType;
+	typedef enum { Text, Int, Float, Time, DiskStat, KByte } ColumnType;
 
-	QStandardItemModel mModel;
+	ListViewModel mModel;
 	QTreeView *mView;
 	ListViewSettings* lvs;
 	QByteArray mHeaderSettings;
