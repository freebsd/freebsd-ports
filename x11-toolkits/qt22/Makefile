# New ports collection makefile for:   qt
# Version required:	1.1
# Date created:		30 Jul 1996
# Whom:			searle@longacre.demon.co.uk
#
# $Id: Makefile,v 1.8 1996/12/11 10:18:45 asami Exp $
#

DISTNAME=	qt-1.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/

MAINTAINER=	searle@longacre.demon.co.uk

USE_GMAKE=	yes
WRKSRC=		$(WRKDIR)/$(DISTNAME)/arch/freebsd-gcc-shared
USE_X11=	yes

MAN1=		moc.1
MAN3=		qaccel.3qt qapplication.3qt qarray.3qt qbitarray.3qt \
		qbitmap.3qt qbitval.3qt qbrush.3qt qbuffer.3qt \
		qbutton.3qt qbuttongroup.3qt qbytearray.3qt \
		qcheckbox.3qt qclipboard.3qt qcloseevent.3qt \
		qcollection.3qt qcolor.3qt qcolorgroup.3qt \
		qcombobox.3qt qconnection.3qt qcursor.3qt \
		qcustomevent.3qt qdatastream.3qt qdate.3qt \
		qdatetime.3qt qdialog.3qt qdict.3qt qdictiterator.3qt \
		qdir.3qt qevent.3qt qfile.3qt qfiledialog.3qt \
		qfileinfo.3qt qfocusevent.3qt qfont.3qt qfontinfo.3qt \
		qfontmetrics.3qt qframe.3qt qgarray.3qt qgcache.3qt \
		qgcacheiterator.3qt qgdict.3qt qgdictiterator.3qt \
		qglist.3qt qglistiterator.3qt qgroupbox.3qt qimage.3qt \
		qimageio.3qt qintdict.3qt qintdictiterator.3qt \
		qiodevice.3qt qkeyevent.3qt qlabel.3qt qlcdnumber.3qt \
		qlineedit.3qt qlist.3qt qlistbox.3qt qlistboxitem.3qt \
		qlistboxpixmap.3qt qlistboxtext.3qt qlistiterator.3qt \
		qlnode.3qt qmenubar.3qt qmenudata.3qt qmessagebox.3qt \
		qmouseevent.3qt qmoveevent.3qt qobject.3qt \
		qpaintdevice.3qt qpaintdevicemetrics.3qt qpainter.3qt \
		qpaintevent.3qt qpalette.3qt qpen.3qt qpicture.3qt \
		qpixmap.3qt qpixmapcache.3qt qpoint.3qt \
		qpointarray.3qt qpopupmenu.3qt qprinter.3qt \
		qpushbutton.3qt qqueue.3qt qradiobutton.3qt \
		qrangecontrol.3qt qrect.3qt qregexp.3qt qregion.3qt \
		qresizeevent.3qt qscrollbar.3qt qsenderobject.3qt \
		qshared.3qt qsignal.3qt qsize.3qt qsocketnotifier.3qt \
		qstack.3qt qstrilist.3qt qstring.3qt qstrlist.3qt \
		qtableview.3qt qtextstream.3qt qtime.3qt qtimer.3qt \
		qtimerevent.3qt qtsmanip.3qt qwidget.3qt qwindow.3qt \
		qwmatrix.3qt QAccel.3qt QApplication.3qt QArray.3qt \
		QBitArray.3qt QBitmap.3qt QBitVal.3qt QBrush.3qt \
		QBuffer.3qt QButton.3qt QButtonGroup.3qt \
		QByteArray.3qt QCheckBox.3qt QClipboard.3qt \
		QCloseEvent.3qt QCollection.3qt QColor.3qt \
		QColorGroup.3qt QComboBox.3qt QConnection.3qt \
		QCursor.3qt QCustomEvent.3qt QDataStream.3qt QDate.3qt \
		QDateTime.3qt QDialog.3qt QDict.3qt QDictIterator.3qt \
		QDir.3qt QEvent.3qt QFile.3qt QFileDialog.3qt \
		QFileInfo.3qt QFocusEvent.3qt QFont.3qt QFontInfo.3qt \
		QFontMetrics.3qt QFrame.3qt QGArray.3qt QGCache.3qt \
		QGCacheIterator.3qt QGDict.3qt QGDictIterator.3qt \
		QGList.3qt QGListIterator.3qt QGroupBox.3qt QImage.3qt \
		QImageIO.3qt QIntDict.3qt QIntDictIterator.3qt \
		QIODevice.3qt QKeyEvent.3qt QLabel.3qt QLCDNumber.3qt \
		QLineEdit.3qt QList.3qt QListBox.3qt QListBoxItem.3qt \
		QListBoxPixmap.3qt QListBoxText.3qt QListIterator.3qt \
		QLNode.3qt QMenuBar.3qt QMenuData.3qt QMessageBox.3qt \
		QMouseEvent.3qt QMoveEvent.3qt QObject.3qt \
		QPaintDevice.3qt QPaintDeviceMetrics.3qt QPainter.3qt \
		QPaintEvent.3qt QPalette.3qt QPen.3qt QPicture.3qt \
		QPixmap.3qt QPixmapCache.3qt QPoint.3qt \
		QPointArray.3qt QPopupMenu.3qt QPrinter.3qt \
		QPushButton.3qt QQueue.3qt QRadioButton.3qt \
		QRangeControl.3qt QRect.3qt QRegExp.3qt QRegion.3qt \
		QResizeEvent.3qt QScrollBar.3qt QSenderObject.3qt \
		QShared.3qt QSignal.3qt QSize.3qt QSocketNotifier.3qt \
		QStack.3qt QStrIList.3qt QString.3qt QStrList.3qt \
		QTableView.3qt QTextStream.3qt QTime.3qt QTimer.3qt \
		QTimerEvent.3qt QTSManip.3qt QWidget.3qt QWindow.3qt \
		QWMatrix.3qt

post-extract:
	cd $(WRKDIR)/$(DISTNAME)/arch; $(GMAKE) freebsd

do-install:
	${INSTALL_PROGRAM} $(WRKDIR)/qt-1.1/bin/moc $(X11BASE)/bin
	${INSTALL_DATA} $(WRKDIR)/qt-1.1/lib/libqt.so.1.1 $(X11BASE)/lib
	/sbin/ldconfig -m $(PREFIX)/lib
	mkdir -p $(PREFIX)/include/X11/qt
	${INSTALL_DATA} $(WRKDIR)/qt-1.1/include/* $(PREFIX)/include/X11/qt
	${INSTALL_MAN} $(WRKDIR)/qt-1.1/man/man1/* $(PREFIX)/man/man1
	${INSTALL_MAN} $(WRKDIR)/qt-1.1/man/man3/* $(PREFIX)/man/man3
	mkdir -p ${PREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKDIR}/qt-1.1/README ${PREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKDIR}/qt-1.1/README.QT ${PREFIX}/share/doc/qt

.include <bsd.port.mk>
