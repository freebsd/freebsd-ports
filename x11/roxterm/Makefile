# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	roxterm
PORTVERSION=	2.6.5
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ 2.0 terminal emulator with tabs

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>0:${PORTSDIR}/devel/py-lockfile \
		docbook-xsl>0:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USE_GNOME=	libglade2 vte
USE_PYTHON_BUILD=	yes
USES=		pkgconfig gettext
USE_AUTOTOOLS=	libtool:env
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=	roxterm.1 \
	roxterm-config.1

MAITCHFLAGS=	CC=${CC};CPP=${CC};CFLAGS=${CFLAGS};PARALLEL=${_make_jobs}

.include <bsd.port.options.mk>

_make_jobs=	${MAKE_JOBS_NUMBER}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|' ${WRKSRC}/maitch.py

do-configure:
	@(cd ${WRKSRC} && ${SETENV} MAITCHFLAGS="${MAITCHFLAGS}" \
		${PYTHON_CMD} mscript.py configure --prefix=${PREFIX} \
		--disable-gtk3 --disable-po4a --disable-git)

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} mscript.py build \
		&& ${PYTHON_CMD} mscript.py install)

do-install:
	(cd ${WRKSRC}/build/usr/local/bin \
		&& ${INSTALL_PROGRAM} * ${PREFIX}/bin)
	(cd ${WRKSRC}/build/usr/local/share/man/man1 \
		&& ${INSTALL_MAN} * ${MANPREFIX}/man/man1)
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/build/usr/local/share/roxterm \
		&& ${COPYTREE_SHARE} . ${DATADIR})
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC}/build/usr/local/share/applications \
		&& ${INSTALL_DATA} * ${DESKTOPDIR})
	@${MKDIR} ${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC}/build/usr/local/share/icons/hicolor/scalable/apps \
		&& ${INSTALL_DATA} * \
		${PREFIX}/share/icons/hicolor/scalable/apps)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/build/usr/local/share/doc/roxterm \
		&& ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
