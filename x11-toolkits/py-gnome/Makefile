# New ports collection makefile for:	py-gtk
# Version required:			0.5.12
# Date created:				12/26/1998
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.22 1999/03/15 03:17:09 nectar Exp $
#

DISTNAME=	pygtk-0.5.12
PKGNAME=	py-gtk-0.5.12
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/python/ \
		ftp://ftp.gimp.org/pub/gtk/python/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/python/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/python/ \
		ftp://stef.u-picardie.fr/mirror/ftp.gimp.org/gtk/python/

MAINTAINER=	nectar@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	gdk_imlib.3:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
MAKE_FLAGS=	OPT="${CFLAGS}"

PLIST=		${WRKDIR}/PLIST
SORT?=		sort

DOCDIR=		share/doc/py-gtk
DOCFILES=	README MAPPING

EXAMDIR=	share/examples/py-gtk
EXAMSUBDIRS=	glade ide imlib neil simple testgtk
EXAMFILES=	glade/README glade/test2.glade glade/glade.py          \
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

# NOTE: for packaging to work properly, this port should be
# built with PREFIX set the same as when the python port
# was built.

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
	@${CP} /dev/null ${PLIST}.dirrm
.for d in ${EXAMSUBDIRS}
	@${MKDIR} ${PREFIX}/${EXAMDIR}/${d}
	@${ECHO} @dirrm ${EXAMDIR}/${d} >> ${PLIST}.dirrm
.endfor
	@${ECHO} @dirrm ${EXAMDIR} >> ${PLIST}.dirrm
.for f in ${EXAMFILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} \
		${PREFIX}/${EXAMDIR}/${f}
	@${ECHO} ${EXAMDIR}/${f} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@${ECHO} @dirrm ${DOCDIR} >> ${PLIST}.dirrm
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DOCDIR}/${f}
	@${ECHO} ${DOCDIR}/${f} >> ${PLIST}
.endfor
.endif
	@${SORT} -r ${PLIST}.dirrm >> ${PLIST}

.include <bsd.port.mk>
