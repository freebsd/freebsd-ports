# New ports collection makefile for:	tint
# Date created:				21 July 2008
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tint2
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

MAKE_JOBS_SAFE=	yes

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

PROJECTHOST=	tint2
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GNOME=	pango glib20
USE_XORG=	xinerama xrandr xdamage xcomposite
USE_EFL=	imlib2

CMAKE_ARGS=	-DENABLE_BATTERY:BOOL=OFF -DMANDIR:PATH=man

PLIST_FILES=	bin/tint2 \
		share/tint2/default_icon.png
PLIST_DIRS=	share/tint2

OPTIONS=	PYCONF "Configuration editing tool (req. python)" on

MAN1=		tint2.1

PORTDOCS=	AUTHORS ChangeLog README

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PYCONF)
USE_PYTHON=	yes
USE_GNOME=	gtk20 pygtk2
CMAKE_ARGS+=	-DENABLE_TINT2CONF:BOOL=ON
PLIST_FILES+=	bin/tint2conf bin/tintwizard.py \
		share/applications/tint2conf.desktop \
		share/pixmaps/tint2conf.png share/pixmaps/tint2conf.svg
PLIST_DIRSTRY=	share/applications
PYCONF_SRC=	${WRKSRC}/src/tint2conf
.else
CMAKE_ARGS+=	-DENABLE_TINT2CONF:BOOL=OFF
.endif

.if !defined(WITHOUT_PYCONF)
post-patch:
	@${MV} ${PYCONF_SRC}/tintwizard.py ${PYCONF_SRC}/tintwizard.py.Dist
	@${SED} -e 's#pidof#pgrep#g' ${PYCONF_SRC}/tintwizard.py.Dist \
		> ${PYCONF_SRC}/tintwizard.py
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tint2 ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/tint2
	${INSTALL_DATA} ${WRKSRC}/default_icon.png ${PREFIX}/share/tint2
	${INSTALL_MAN} ${WRKSRC}/doc/tint2.1 ${MANPREFIX}/man/man1
.if defined(WITH_PYCONF)
	${INSTALL_PROGRAM} ${PYCONF_SRC}/tint2conf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${PYCONF_SRC}/tintwizard.py ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.png ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.svg ${PREFIX}/share/pixmaps
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@for file in ${RCS}; do \
	${INSTALL_DATA} ${WRKSRC}/sample/$${file} ${EXAMPLESDIR}; \
	done
RCS=	icon_and_text_1.tint2rc icon_and_text_2.tint2rc icon_and_text_3.tint2rc icon_and_text_4.tint2rc icon_only_1.tint2rc icon_only_2.tint2rc icon_only_3.tint2rc icon_only_4.tint2rc icon_only_6.tint2rc icon_only_7.tint2rc text_only_1.tint2rc text_only_2.tint2rc text_only_3.tint2rc text_only_4.tint2rc text_only_5.tint2rc text_only_6.tint2rc tint2rc
.for file in ${RCS}
PLIST_FILES+=	${EXAMPLESDIR_REL}/${file}
.endfor
PLIST_DIRS+=	${EXAMPLESDIR_REL}
.endif

.include <bsd.port.post.mk>
