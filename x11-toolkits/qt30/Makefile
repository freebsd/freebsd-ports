# New ports collection makefile for:   qt
# Version required:	1.42
# Date created:		30 Jul 1996
# Whom:			searle@longacre.demon.co.uk
#
# $Id: Makefile,v 1.29 1998/11/23 17:41:10 andreas Exp $
#

DISTNAME=	qt-1.42
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.troll.no/qt/source/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3

USE_GMAKE=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	QTDIR=${WRKSRC}

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
VERSION=	2
.else
VERSION=	2.0
.endif

MAN1=	moc.1
MAN3=   QAccel.3qt QApplication.3qt QArray.3qt QAsyncIO.3qt \
	QBitArray.3qt QBitVal.3qt QBitmap.3qt QBoxLayout.3qt \
	QBrush.3qt QBuffer.3qt QButton.3qt QButtonGroup.3qt \
	QByteArray.3qt QCache.3qt QCacheIterator.3qt QCheckBox.3qt \
	QCheckListItem.3qt QChildEvent.3qt QClipboard.3qt \
	QCloseEvent.3qt QCollection.3qt QColor.3qt QColorGroup.3qt \
	QComboBox.3qt QConnection.3qt QCursor.3qt QCustomEvent.3qt \
	QDataPump.3qt QDataSink.3qt QDataSource.3qt QDataStream.3qt \
	QDate.3qt QDateTime.3qt QDialog.3qt QDict.3qt QDictIterator.3qt \
	QDir.3qt QDoubleValidator.3qt QDragMoveEvent.3qt QDragObject.3qt \
	QDropEvent.3qt QEvent.3qt QFile.3qt QFileDialog.3qt \
	QFileIconProvider.3qt QFileInfo.3qt QFocusData.3qt \
	QFocusEvent.3qt QFont.3qt QFontInfo.3qt QFontMetrics.3qt \
	QFrame.3qt QGArray.3qt QGCache.3qt QGCacheIterator.3qt \
	QGDict.3qt QGDictIterator.3qt QGIFFormat.3qt QGIFFormatType.3qt \
	QGLContext.3qt QGLFormat.3qt QGLWidget.3qt QGList.3qt \
	QGListIterator.3qt QGManager.3qt QGridLayout.3qt QGroupBox.3qt \
	QHBoxLayout.3qt QHeader.3qt QIODevice.3qt QIODeviceSource.3qt \
	QIconSet.3qt QImage.3qt QImageConsumer.3qt QImageDecoder.3qt \
	QImageDrag.3qt QImageFormat.3qt QImageFormatType.3qt \
	QImageIO.3qt QIntCache.3qt QIntCacheIterator.3qt QIntDict.3qt \
	QIntDictIterator.3qt QIntValidator.3qt QKeyEvent.3qt \
	QLCDNumber.3qt QLNode.3qt QLabel.3qt QLayout.3qt QLineEdit.3qt \
	QList.3qt QListBox.3qt QListBoxItem.3qt QListBoxPixmap.3qt \
	QListBoxText.3qt QListIterator.3qt QListView.3qt \
	QListViewItem.3qt QMainWindow.3qt QMenuBar.3qt QMenuData.3qt \
	QMessageBox.3qt QMouseEvent.3qt QMoveEvent.3qt QMovie.3qt \
	QMultiLineEdit.3qt QNPInstance.3qt QNPStream.3qt QNPWidget.3qt \
	QNPlugin.3qt QObject.3qt QPaintDevice.3qt QPaintDeviceMetrics.3qt \
	QPaintEvent.3qt QPainter.3qt QPalette.3qt QPen.3qt QPicture.3qt \
	QPixmap.3qt QPixmapCache.3qt QPoint.3qt QPointArray.3qt \
	QPointVal.3qt QPopupMenu.3qt QPrintDialog.3qt QPrinter.3qt \
	QProgressBar.3qt QProgressDialog.3qt QPtrDict.3qt \
	QPtrDictIterator.3qt QPushButton.3qt QQueue.3qt QRadioButton.3qt \
	QRangeControl.3qt QRect.3qt QRegExp.3qt QRegion.3qt \
	QResizeEvent.3qt QScrollBar.3qt QScrollView.3qt QSemiModal.3qt \
	QShared.3qt QSignal.3qt QSignalMapper.3qt QSize.3qt \
	QSlider.3qt QSocketNotifier.3qt QSpinBox.3qt QSplitter.3qt \
	QStack.3qt QStatusBar.3qt QStoredDrag.3qt QStrIList.3qt \
	QStrList.3qt QString.3qt QTabBar.3qt QTabDialog.3qt \
	QTableView.3qt QTextDrag.3qt QTextStream.3qt QTime.3qt \
	QTimer.3qt QTimerEvent.3qt QToolBar.3qt QToolButton.3qt \
	QToolTip.3qt QToolTipGroup.3qt QUrlDrag.3qt QVBoxLayout.3qt \
	QValidator.3qt QWMatrix.3qt QWhatsThis.3qt QWidget.3qt \
	QWidgetStack.3qt QWindow.3qt QXtApplication.3qt QXtWidget.3qt \
	qaccel.3qt qapplication.3qt qarray.3qt qasyncio.3qt \
	qbitarray.3qt qbitmap.3qt qbitval.3qt qboxlayout.3qt \
	qbrush.3qt qbuffer.3qt qbutton.3qt qbuttongroup.3qt \
	qbytearray.3qt qcache.3qt qcacheiterator.3qt qcheckbox.3qt \
	qchecklistitem.3qt qchildevent.3qt qclipboard.3qt \
	qcloseevent.3qt qcollection.3qt qcolor.3qt qcolorgroup.3qt \
	qcombobox.3qt qconnection.3qt qcursor.3qt qcustomevent.3qt \
	qdatapump.3qt qdatasink.3qt qdatasource.3qt qdatastream.3qt \
	qdate.3qt qdatetime.3qt qdialog.3qt qdict.3qt qdictiterator.3qt \
	qdir.3qt qdoublevalidator.3qt qdragmoveevent.3qt qdragobject.3qt \
	qdropevent.3qt qevent.3qt qfile.3qt qfiledialog.3qt \
	qfileiconprovider.3qt qfileinfo.3qt qfocusdata.3qt \
	qfocusevent.3qt qfont.3qt qfontinfo.3qt qfontmetrics.3qt \
	qframe.3qt qgarray.3qt qgcache.3qt qgcacheiterator.3qt \
	qgdict.3qt qgdictiterator.3qt qgifformat.3qt qgifformattype.3qt \
	qglcontext.3qt qglformat.3qt qglist.3qt qglistiterator.3qt \
	qglwidget.3qt qgmanager.3qt qgridlayout.3qt qgroupbox.3qt \
	qhboxlayout.3qt qheader.3qt qiconset.3qt qimage.3qt \
	qimageconsumer.3qt qimagedecoder.3qt qimagedrag.3qt \
	qimageformat.3qt qimageformattype.3qt qimageio.3qt \
	qintcache.3qt qintcacheiterator.3qt qintdict.3qt \
	qintdictiterator.3qt qintvalidator.3qt qiodevice.3qt \
	qiodevicesource.3qt qkeyevent.3qt qlabel.3qt qlayout.3qt \
	qlcdnumber.3qt qlineedit.3qt qlist.3qt qlistbox.3qt \
	qlistboxitem.3qt qlistboxpixmap.3qt qlistboxtext.3qt \
	qlistiterator.3qt qlistview.3qt qlistviewitem.3qt qlnode.3qt \
	qmainwindow.3qt qmenubar.3qt qmenudata.3qt qmessagebox.3qt \
	qmouseevent.3qt qmoveevent.3qt qmovie.3qt qmultilineedit.3qt \
	qnpinstance.3qt qnplugin.3qt qnpstream.3qt qnpwidget.3qt \
	qobject.3qt qpaintdevice.3qt qpaintdevicemetrics.3qt \
	qpainter.3qt qpaintevent.3qt qpalette.3qt qpen.3qt qpicture.3qt \
	qpixmap.3qt qpixmapcache.3qt qpoint.3qt qpointarray.3qt \
	qpointval.3qt qpopupmenu.3qt qprintdialog.3qt qprinter.3qt \
	qprogressbar.3qt qprogressdialog.3qt qptrdict.3qt \
	qptrdictiterator.3qt qpushbutton.3qt qqueue.3qt qradiobutton.3qt \
	qrangecontrol.3qt qrect.3qt qregexp.3qt qregion.3qt \
	qresizeevent.3qt qscrollbar.3qt qscrollview.3qt qsemimodal.3qt \
	qshared.3qt qsignal.3qt qsignalmapper.3qt qsize.3qt \
	qslider.3qt qsocketnotifier.3qt qspinbox.3qt qsplitter.3qt \
	qstack.3qt qstatusbar.3qt qstoreddrag.3qt qstrilist.3qt \
	qstring.3qt qstrlist.3qt qtabbar.3qt qtabdialog.3qt \
	qtableview.3qt qtextdrag.3qt qtextstream.3qt qtime.3qt \
	qtimer.3qt qtimerevent.3qt qtoolbar.3qt qtoolbutton.3qt \
	qtooltip.3qt qtooltipgroup.3qt qurldrag.3qt qvalidator.3qt \
	qvboxlayout.3qt qwhatsthis.3qt qwidget.3qt qwidgetstack.3qt \
	qwindow.3qt qwmatrix.3qt qxtapplication.3qt qxtwidget.3qt

post-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} freebsd-g++-shared

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc $(PREFIX)/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libqt.so.${VERSION} $(PREFIX)/lib
	${LN} -sf $(PREFIX)/lib/libqt.so.$(VERSION) $(PREFIX)/lib/libqt.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m $(PREFIX)/lib
	${MKDIR} $(PREFIX)/include/X11/qt
	${INSTALL_DATA} ${WRKSRC}/include/* $(PREFIX)/include/X11/qt
	${INSTALL_MAN} ${WRKSRC}/man/man1/* $(PREFIX)/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/* $(PREFIX)/man/man3
	${MKDIR} ${PREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKSRC}/README.QT ${PREFIX}/share/doc/qt

.include <bsd.port.post.mk>
