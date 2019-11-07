# $FreeBSD$

PORTNAME=	compton
PORTVERSION=	20160907
PORTREVISION=	4
CATEGORIES=	x11-wm

MAINTAINER=	femc7488@gmail.com
COMMENT=	Feature-rich compositing window manager for X11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xprop:x11/xprop \
		xwininfo:x11/xwininfo

CONFLICTS_INSTALL=	compton-yshui # bin/compton

USE_GITHUB=	yes
GH_ACCOUNT=	chjj
GH_TAGNAME=	b7f43ee

USES=		gmake pkgconfig xorg
USE_XORG=	x11 xcomposite xdamage xext xfixes xrandr xrender

MAKE_ARGS=	COMPTON_VERSION=git-${PORTVERSION}-${GH_TAGNAME} \
		XDGDIR=${LOCALBASE}/etc/xdg
ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	CONFIG PCRE DRM OPENGL DBUS XINERAMA DOCS
OPTIONS_DEFAULT=	CONFIG PCRE DRM OPENGL DBUS XINERAMA

CONFIG_DESC=	Configuration file parsing support
PCRE_DESC=	Blacklist support (via libpcre)
DRM_DESC=	DRM VSync method support
OPENGL_DESC=	GLX backend, OpenGL VSync method, etc.
DOCS_DESC=	Build manpages (requires AsciiDoc/DocBook)

CONFIG_LIB_DEPENDS=	libconfig.so:devel/libconfig
CONFIG_MAKE_ARGS_OFF=	NO_LIBCONFIG=yes

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_MAKE_ARGS_OFF=	NO_REGEX_PCRE=yes

DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_MAKE_ARGS_OFF=	NO_VSYNC_DRM=yes

OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_MAKE_ARGS_OFF=	NO_VSYNC_OPENGL=yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MAKE_ARGS_OFF=	NO_DBUS=yes

XINERAMA_USE=		XORG=xinerama
XINERAMA_MAKE_ARGS_OFF=	NO_XINERAMA=yes

DOCS_BUILD_DEPENDS=	a2x:textproc/asciidoc \
			xsltproc:textproc/libxslt \
			docbook-xml>0:textproc/docbook-xml \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
DOCS_MAKE_ARGS=		DOCDIR=${DOCSDIR} MANDIR=${MANPREFIX}/man/man1
DOCS_ALL_TARGET=	docs
DOCS_PLIST_FILES=	man/man1/compton.1.gz man/man1/compton-trans.1.gz
DOCS_PORTDOCS=		README.md cdbus-driver.sh

post-patch:
	@${REINPLACE_CMD} -e '/config_system_dir/s|/etc|${LOCALBASE}&|' \
		${WRKSRC}/src/compton.c

.include <bsd.port.mk>
