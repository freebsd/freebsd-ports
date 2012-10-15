# $FreeBSD$
#

PORTNAME=	keybinder
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://kaizer.se/publicfiles/${PORTNAME}/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Library for registering keyboard shortcuts

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	PYTHON LUA
OPTIONS_DEFAULT=	PYTHON

# Override LUA description
LUA_DESC=	Lua bindings

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
USE_GNOME+=	pygtk2 pygobject
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1+
CONFIGURE_ARGS+=	--with-lua-includes=${LUA_INCDIR}
PLIST_SUB+=	LUA=""
.else
CONFIGURE_ARGS+=	--disable-lua
PLIST_SUB+=	LUA="@comment "
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -i '' -e 's,lua5,lua-5,' ${WRKSRC}/examples/Makefile
	@${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
