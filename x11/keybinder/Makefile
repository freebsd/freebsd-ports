# $FreeBSD$

PORTNAME=	keybinder
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for registering keyboard shortcuts

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gtk20 introspection:build
USE_XORG=	x11 xext xrender
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES PYTHON LUA
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

# Override LUA description
LUA_DESC=	Lua bindings

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2
USE_GNOME+=	pygtk2
.else
CONFIGURE_ARGS+=	--disable-python
.endif

.if ${PORT_OPTIONS:MLUA}
USES+=		lua:51
CONFIGURE_ARGS+=	--with-lua-includes=${LUA_INCDIR}
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -i '' -e 's|lua5.1|lua-${LUA_VER}|g' ${WRKSRC}/examples/Makefile
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
