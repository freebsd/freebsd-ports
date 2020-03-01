# $FreeBSD$

PORTNAME=	keybinder
PORTVERSION=	0.3.1
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for registering keyboard shortcuts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	engla

USES=		autoreconf gmake gnome libtool pathfix pkgconfig xorg
USE_GNOME=	gtk20 introspection:build
USE_XORG=	x11 xext xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-python
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES DOCS LUA
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_CONFIGURE_ON=	--enable-gtk-doc

# Override LUA description
LUA_DESC=		Lua bindings
LUA_USES=		lua:51
LUA_CONFIGURE_ON=	--with-lua-includes=${LUA_INCDIR}
LUA_CONFIGURE_OFF=	--disable-lua

post-patch-DOCS-off:
	@${REINPLACE_CMD} -E '/GTK_DOC_CHECK|docs/d' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^SUBDIRS/s, docs,,' ${WRKSRC}/Makefile.am

pre-configure-DOCS-on:
	@(cd ${CONFIGURE_WRKSRC} && ${LOCALBASE}/bin/gtkdocize)

post-build-EXAMPLES-on:
	@${REINPLACE_CMD} -i '' -e \
		's|lua5.1|lua-${LUA_VER}|g' ${WRKSRC}/examples/Makefile

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
