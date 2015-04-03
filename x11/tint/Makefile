# $FreeBSD$

PORTNAME=	tint2
PORTVERSION=	0.11
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libImlib2.so:${PORTSDIR}/graphics/imlib2

PROJECTHOST=	tint2
USES=		alias cmake pkgconfig tar:bzip2
USE_GNOME=	glib20 pango
USE_XORG=	xdamage xcomposite xinerama xrandr

CMAKE_ARGS=	-DENABLE_BATTERY:BOOL=ON -DMANDIR:PATH=man

OPTIONS_DEFINE=	DOCS EXAMPLES PYCONF
OPTIONS_DEFAULT=	PYCONF
OPTIONS_SUB=	yes
PYCONF_DESC=	Configuration editing tool (requires python)

PORTEXAMPLES=	icon_and_text_1.tint2rc icon_and_text_2.tint2rc \
		icon_and_text_3.tint2rc icon_and_text_4.tint2rc \
		icon_only_1.tint2rc icon_only_2.tint2rc icon_only_3.tint2rc \
		icon_only_4.tint2rc icon_only_6.tint2rc icon_only_7.tint2rc \
		text_only_1.tint2rc text_only_2.tint2rc text_only_3.tint2rc \
		text_only_4.tint2rc text_only_5.tint2rc text_only_6.tint2rc tint2rc
PORTDOCS=	AUTHORS ChangeLog README

PYCONF_USES=	python
PYCONF_USE=	gnome=gtk20,pygtk2
PYCONF_CMAKE_ON=	-DENABLE_TINT2CONF:BOOL=ON
PYCONF_CMAKE_OFF=	-DENABLE_TINT2CONF:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYCONF}
PYCONF_SRC=	${WRKSRC}/src/tint2conf
post-patch:
	@${MV} ${PYCONF_SRC}/tintwizard.py ${PYCONF_SRC}/tintwizard.py.Dist
	@${SED} -e 's#pidof#pgrep#g' ${PYCONF_SRC}/tintwizard.py.Dist \
		> ${PYCONF_SRC}/tintwizard.py
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tint2 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/tint2
	${INSTALL_DATA} ${WRKSRC}/default_icon.png ${STAGEDIR}${PREFIX}/share/tint2
	${INSTALL_MAN} ${WRKSRC}/doc/tint2.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MPYCONF}
	${INSTALL_PROGRAM} ${PYCONF_SRC}/tint2conf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${PYCONF_SRC}/tintwizard.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.svg ${STAGEDIR}${PREFIX}/share/pixmaps
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR}  ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/sample/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
