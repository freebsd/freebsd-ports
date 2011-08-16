# New ports collection makefile for:	keybinder
# Date created:				2011-02-21
# Whom:			Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	keybinder
PORTVERSION=	0.2.2
CATEGORIES=	x11
MASTER_SITES=	http://kaizer.se/publicfiles/${PORTNAME}/

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Library for registering keyboard shortcuts

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 pkgconfig
USE_LDCONFIG=	yes

PORTEXAMPLES=	*

OPTIONS=	PYTHON	"Install Python bindings"	on \
		LUA	"Install Lua bindings"		off

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
USE_GNOME+=	pygtk2 pygobject
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_LUA)
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
