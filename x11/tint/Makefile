# $FreeBSD$

PORTNAME=	tint2
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

MAKE_JOBS_SAFE=	yes

PROJECTHOST=	tint2
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GNOME=	pango glib20
USE_XORG=	xinerama xrandr xdamage xcomposite
USE_EFL=	imlib2

CMAKE_ARGS=	-DENABLE_BATTERY:BOOL=ON -DMANDIR:PATH=man

PLIST_FILES=	bin/tint2 \
		share/tint2/default_icon.png
PLIST_DIRS=	share/tint2

OPTIONS_DEFINE=	PYCONF DOCS EXAMPLES
OPTIONS_DEFAULT=	PYCONF
PYCONF_DESC=	Configuration editing tool (req. python)

MAN1=		tint2.1

PORTDOCS=	AUTHORS ChangeLog README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYCONF}
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

.if ${PORT_OPTIONS:MPYCONF}
post-patch:
	@${MV} ${PYCONF_SRC}/tintwizard.py ${PYCONF_SRC}/tintwizard.py.Dist
	@${SED} -e 's#pidof#pgrep#g' ${PYCONF_SRC}/tintwizard.py.Dist \
		> ${PYCONF_SRC}/tintwizard.py
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tint2 ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/tint2
	@${INSTALL_DATA} ${WRKSRC}/default_icon.png ${PREFIX}/share/tint2
	@${INSTALL_MAN} ${WRKSRC}/doc/tint2.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MPYCONF}
	@${INSTALL_PROGRAM} ${PYCONF_SRC}/tint2conf ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${PYCONF_SRC}/tintwizard.py ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.desktop ${PREFIX}/share/applications
	@${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.png ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.svg ${PREFIX}/share/pixmaps
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@for f in ${RCS}; do \
	${INSTALL_DATA} ${WRKSRC}/sample/$${f} ${EXAMPLESDIR}; \
	done
RCS=	icon_and_text_1.tint2rc icon_and_text_2.tint2rc icon_and_text_3.tint2rc icon_and_text_4.tint2rc icon_only_1.tint2rc icon_only_2.tint2rc icon_only_3.tint2rc icon_only_4.tint2rc icon_only_6.tint2rc icon_only_7.tint2rc text_only_1.tint2rc text_only_2.tint2rc text_only_3.tint2rc text_only_4.tint2rc text_only_5.tint2rc text_only_6.tint2rc tint2rc
.for f in ${RCS}
PLIST_FILES+=	${EXAMPLESDIR_REL}/${f}
.endfor
PLIST_DIRS+=	${EXAMPLESDIR_REL}
.endif

.include <bsd.port.mk>
