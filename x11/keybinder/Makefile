# $FreeBSD$

PORTNAME=	keybinder
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Library for registering keyboard shortcuts

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_XORG=	x11 xext xrender
USES=		gmake pkgconfig pathfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES PYTHON LUA
OPTIONS_DEFAULT=	PYTHON

# Override LUA description
LUA_DESC=	Lua bindings

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
USE_GNOME+=	pygtk2
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

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc \
	--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	DOCS=""
.else
CONFIGURE_ARGS+=--disable-gtk-doc-html \
	--without-html-dir
PLIST_SUB+=	DOCS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -i '' -e 's|lua5.1|lua-5.1|g' ${WRKSRC}/examples/Makefile
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
