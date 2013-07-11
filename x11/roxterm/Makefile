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
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_GNOME=	libglade2 librsvg2 vte
USE_PYTHON_BUILD=	yes
USE_AUTOTOOLS=	libtool:env
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=	roxterm.1 \
	roxterm-config.1

MAITCHFLAGS=	CC=${CC};CPP=${CC};CFLAGS=${CFLAGS};PARALLEL=${MAKE_JOBS_NUMBER}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|' ${WRKSRC}/maitch.py
	@${REINPLACE_CMD} -e \
		's|x-www-browser|xdg-open|' ${WRKSRC}/src/uri.c

do-configure:
	@(cd ${WRKSRC} && ${SETENV} MAITCHFLAGS="${MAITCHFLAGS}" \
		${PYTHON_CMD} mscript.py configure --prefix=${PREFIX} \
		--disable-gtk3 --disable-gettext --disable-po4a --disable-git)

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} mscript.py build)
	@${MKDIR} ${WRKSRC}/build/po
.for i in es fr pt_BR ru uk
	@(cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt \
		-o ${WRKSRC}/build/po/${i}.mo ${i}.po)
.endfor

do-install:
	(cd ${WRKSRC}/build && ${INSTALL_PROGRAM} roxterm ${PREFIX}/bin)
	(cd ${WRKSRC}/build && ${INSTALL_SCRIPT} roxterm-config ${PREFIX}/bin)
	(cd ${WRKSRC}/build && ${INSTALL_MAN} *.1 ${MANPREFIX}/man/man1)
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} roxterm.desktop ${DESKTOPDIR})
	@${MKDIR} ${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC} && ${INSTALL_DATA} roxterm.svg \
		${PREFIX}/share/icons/hicolor/scalable/apps)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/src && ${INSTALL_DATA} roxterm-config.ui ${DATADIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} Config ${DATADIR})
.for i in es fr pt_BR ru uk
	@${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	(cd ${WRKSRC}/build/po && ${INSTALL_DATA} ${i}.mo \
		${PREFIX}/share/locale/${i}/LC_MESSAGES/roxterm.mo)
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog README
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
	@${MKDIR} ${DOCSDIR}/en
	@(cd ${WRKSRC}/Help/en && ${INSTALL_DATA} * ${DOCSDIR}/en)
	@${MKDIR} ${DOCSDIR}/lib
	@(cd ${WRKSRC}/Help/lib && ${INSTALL_DATA} * ${DOCSDIR}/lib)
.endif

.include <bsd.port.mk>
