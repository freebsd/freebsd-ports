# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	roxterm
PORTVERSION=	3.3.2
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ terminal emulator with tabs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>0:devel/py-lockfile \
		docbook-xsl>0:textproc/docbook-xsl \
		itstool:textproc/itstool \
		po4a:textproc/po4a
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libgnutls.so:security/gnutls
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		gettext libtool:build pkgconfig python:build tar:xz
USE_XORG=	ice sm x11
USE_GNOME=	cairo librsvg2:run libxslt:build
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

MAITCHFLAGS=	DISABLE_GIT=True;
MAITCHFLAGS+=	CC=${CC};GCC=${CC};CPP=${CC};CFLAGS=${CFLAGS};
MAITCHFLAGS+=	PARALLEL=${MAKE_JOBS_NUMBER};PREFIX=${PREFIX};

.include <bsd.port.options.mk>

USE_GNOME+=	vte3

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|' ${WRKSRC}/maitch.py
	@${REINPLACE_CMD} -e \
		's|x-www-browser|xdg-open|' ${WRKSRC}/src/uri.c

do-configure:
	@(cd ${WRKSRC} && ${SETENV} MAITCHFLAGS="${MAITCHFLAGS}" \
		${PYTHON_CMD} mscript.py configure)

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} mscript.py build)

do-install:
.for i in roxterm roxterm-config
	(cd ${WRKSRC}/build && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin)
.endfor
	(cd ${WRKSRC}/build && ${INSTALL_MAN} *.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
.for i in es fr pt_BR ru uk
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/${i}/man1
	(cd ${WRKSRC}/build/po4a/${i} && ${INSTALL_MAN} *.1 \
		${STAGEDIR}${MANPREFIX}/man/${i}/man1)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	(cd ${WRKSRC}/build && ${INSTALL_DATA} roxterm.appdata.xml \
		${STAGEDIR}${PREFIX}/share/appdata)
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
.for i in en es fr lib pt_BR ru uk
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
	(cd ${WRKSRC}/Help/${i} && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/${i})
.endfor

.include <bsd.port.mk>
