# New ports collection makefile for:	py-gnome
# Version required:			1.0.1
# Date created:				03/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	gnome-python-1.0.3
PKGNAME=	py-gnome-1.0.3
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/python/ \
		ftp://ftp.gimp.org/pub/gtk/python/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/python/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/python/ \
		ftp://stef.u-picardie.fr/mirror/ftp.gimp.org/gtk/python/

MAINTAINER=	nectar@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	capplet.1:${PORTSDIR}/sysutils/gnomecontrolcenter
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
PLIST=		${WRKSRC}/PLIST

DOCDIR=		share/doc/py-gnome
DOCFILES=	README:py-gnome.README pygtk/README:py-gtk.README      \
		pygtk/MAPPING:MAPPING.py-gtk

EGDIR=		share/examples/py-gnome
EGSUBDIRS=	gnome gtk gtk/glade gtk/ide gtk/imlib gtk/neil         \
		gtk/simple gtk/testgtk
EGGNOME=	canvas.py fifteen.py html_demo.py stock_demo.py        \
		ted_demo.py uiinfo_demo.py zterm.py
EGGTK=		glade/README glade/test2.glade glade/glade.py          \
		glade/test.glade ide/gtkcons.py ide/gtkdb.py           \
		ide/edit.py ide/browse.py ide/minibreak.xpm ide/README \
		ide/gtkprof.py ide/pyide.py ide/break.xpm              \
		ide/return.xpm ide/next.xpm ide/continue.xpm           \
		ide/step.xpm ide/edit.xpm ide/run.xpm ide/quit.xpm     \
		imlib/view.py neil/TAppli.py neil/TAppli2.py           \
		neil/TAppli3.py neil/TAppli4.py neil/TAppli5.py        \
		neil/bomb.xpm neil/gtk-logo.xpm neil/question.xpm      \
		neil/notebook.py neil/README simple/hello1.py          \
		simple/hello2.py simple/simple1.py simple/simple2.py   \
		simple/tooltip1.py simple/tooltip2.py                  \
		simple/scribble.py simple/dnd.py simple/dndpixmap.py   \
		simple/README testgtk/testgtk.py testgtk/test.xpm      \
		testgtk/testgtkrc testgtk/README

SORT?=		sort

# Examples and docs are added to the packing list on the fly.
pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
	@${CP} /dev/null ${PLIST}.dirrm
.for d in ${EGSUBDIRS}
	@${MKDIR} ${PREFIX}/${EGDIR}/${d}
	@${ECHO} @dirrm ${EGDIR}/${d} >> ${PLIST}.dirrm
.endfor
	@${ECHO} @dirrm ${EGDIR} >> ${PLIST}.dirrm
.for f in ${EGGNOME}
	${INSTALL_DATA} ${WRKSRC}/pygnome/examples/${f}                \
		${PREFIX}/${EGDIR}/gnome/${f}
	@${ECHO} ${EGDIR}/gnome/${f} >> ${PLIST}
.endfor
.for f in ${EGGTK}
	${INSTALL_DATA} ${WRKSRC}/pygtk/examples/${f}                  \
		${PREFIX}/${EGDIR}/gtk/${f}
	@${ECHO} ${EGDIR}/gtk/${f} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@${ECHO} @dirrm ${DOCDIR} >> ${PLIST}.dirrm
	@for i in ${DOCFILES}; do                                      \
		src=`${ECHO} $$i | ${AWK} -F: '{ print $$1 }'`;        \
		dst=`${ECHO} $$i | ${AWK} -F: '{ print $$2 }'`;        \
		${INSTALL_DATA} ${WRKSRC}/$$src                        \
			${PREFIX}/${DOCDIR}/$$dst &&                   \
		${ECHO} ${DOCDIR}/$$dst >> ${PLIST};                   \
	done
.endif
	@${SORT} -r ${PLIST}.dirrm >> ${PLIST}

.include <bsd.port.mk>
