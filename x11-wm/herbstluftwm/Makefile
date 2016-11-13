# $FreeBSD$

PORTNAME=	herbstluftwm
PORTVERSION=	0.7.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://herbstluftwm.org/tarballs/

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Manual tiling window manager for X11

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lib gettext-runtime gmake pkgconfig shebangfix
SHEBANG_FILES=	scripts/*.sh share/autostart share/*.sh
USE_XORG=	x11 xext xinerama
USE_GNOME=	glib20

MAKE_ARGS=	PREFIX=${PREFIX} SYSCONFDIR=${PREFIX}/etc \
		DOCSDIR=${DOCSDIR} EXAMPLESDIR=${EXAMPLESDIR} \
		MANDIR=${PREFIX}/man LDXX=${CXX} \
		COLOR=0

OPTIONS_DEFINE=	BASH ZSH DOCS EXAMPLES DEFAULTCONF
DEFAULTCONF_DESC=Install default configuration (requires bash)
OPTIONS_DEFAULT+=DEFAULTCONF
OPTIONS_SUB=	yes

ALL_TARGET=	all-nodoc
INSTALL_TARGET=	install-nodoc
DOCS_ALL_TARGET=	doc
DOCS_INSTALL_TARGET=	install
DEFAULTCONF_RUN_DEPENDS=bash:shells/bash

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e '/LICENSEDIR/d' ${WRKSRC}/Makefile
.if ! ${PORT_OPTIONS:MBASH}
	${REINPLACE_CMD} -e '/BASHCOMPLETIONDIR/d' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MZSH}
	${REINPLACE_CMD} -e '/ZSHCOMPLETIONDIR/d' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e '/EXAMPLESDIR/d' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MDEFAULTCONF}
	${REINPLACE_CMD} -e '/CONFIGDIR/d' ${WRKSRC}/Makefile
.endif

do-install-DOCS-off:
	${MKDIR} ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${MANPREFIX}/man/man7
	${INSTALL_MAN} ${WRKSRC}/doc/*.7 ${STAGEDIR}${MANPREFIX}/man/man7

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/herbst*

.include <bsd.port.mk>
