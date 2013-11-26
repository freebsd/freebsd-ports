# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	roxterm
PORTVERSION=	2.7.2
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ 2.0 terminal emulator with tabs

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>0:${PORTSDIR}/devel/py-lockfile \
		docbook-xsl>0:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_GNOME=	libglade2 librsvg2 vte
USE_PYTHON_BUILD=	yes
USE_AUTOTOOLS=	libtool:env
INSTALLS_ICONS=	yes

MAITCHFLAGS=	CC=${CC};GCC=${CC};CPP=${CC};CFLAGS=${CFLAGS};PARALLEL=${MAKE_JOBS_NUMBER}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|' ${WRKSRC}/maitch.py
	@${REINPLACE_CMD} -e \
		's|x-www-browser|xdg-open|' ${WRKSRC}/src/uri.c

do-configure:
	@(cd ${WRKSRC} && ${SETENV} MAITCHFLAGS="${MAITCHFLAGS}" \
		${PYTHON_CMD} mscript.py configure --prefix=${PREFIX} \
		--disable-gtk3 --disable-po4a --disable-git)

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} mscript.py build)

do-install:
	(cd ${WRKSRC}/build && ${INSTALL_PROGRAM} roxterm \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/build && ${INSTALL_SCRIPT} roxterm-config \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/build && ${INSTALL_MAN} *.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC} && ${INSTALL_DATA} roxterm.desktop \
		${STAGEDIR}${DESKTOPDIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC} && ${INSTALL_DATA} roxterm.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src && ${INSTALL_DATA} roxterm-config.ui \
		${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} Config ${STAGEDIR}${DATADIR})
.for i in es fr pt_BR ru uk
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES
	(cd ${WRKSRC}/build/po && ${INSTALL_DATA} ${i}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/roxterm.mo)
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog README
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/en
	@(cd ${WRKSRC}/Help/en && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/en)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/lib
	@(cd ${WRKSRC}/Help/lib && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/lib)

.include <bsd.port.mk>
