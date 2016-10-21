# $FreeBSD$

PORTNAME=	keybinder
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for registering keyboard shortcuts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc

USE_GITHUB=	yes
GH_ACCOUNT=	engla

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_GNOME=	gtk20 introspection:build
USE_XORG=	x11 xext xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		EXAMPLES LUA PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

# Override LUA description
LUA_DESC=		Lua bindings
LUA_USES=		lua:51
LUA_CONFIGURE_ON=	--with-lua-includes=${LUA_INCDIR}
LUA_CONFIGURE_OFF=	--disable-lua
PYTHON_USES=		python:2
PYTHON_USE=		gnome=pygtk2
PYTHON_CONFIGURE_OFF=	--disable-python

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${LOCALBASE}/bin/gtkdocize)

post-build-EXAMPLES-on:
	@${REINPLACE_CMD} -i '' -e \
		's|lua5.1|lua-${LUA_VER}|g' ${WRKSRC}/examples/Makefile

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
