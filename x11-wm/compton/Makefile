# $FreeBSD$

PORTNAME=	compton
PORTVERSION=	20160907
CATEGORIES=	x11-wm

MAINTAINER=	femc7488@gmail.com
COMMENT=	Feature-rich compositing window manager for X11

LICENSE=	MIT

LIB_DEPENDS=	libconfig.so:devel/libconfig
RUN_DEPENDS=	xprop:x11/xprop \
		xwininfo:x11/xwininfo

USE_GITHUB=	yes
GH_ACCOUNT=	chjj
GH_TAGNAME=	b7f43ee

USES=		gmake pkgconfig
USE_XORG=	x11 xcomposite xdamage xext xfixes xrandr xrender xinerama

MAKE_ARGS=	COMPTON_VERSION=git-${PORTVERSION}-${GH_TAGNAME} \
		XDGDIR=${LOCALBASE}/etc/xdg
ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	PCRE DRM OPENGL DBUS DOCS
OPTIONS_DEFAULT=	PCRE DRM OPENGL DBUS

PCRE_DESC=	Blacklist support (via libpcre)
DRM_DESC=	DRM support
DOCS_DESC=	Build manpages (requires AsciiDoc/DocBook)

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_MAKE_ARGS_OFF=	NO_REGEX_PCRE=yes

DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_MAKE_ARGS_OFF=	NO_VSYNC_DRM=yes

OPENGL_USE=		GL=gl
OPENGL_MAKE_ARGS_OFF=	NO_VSYNC_OPENGL=yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MAKE_ARGS_OFF=	NO_DBUS=yes

DOCS_BUILD_DEPENDS=	a2x:textproc/asciidoc \
			xsltproc:textproc/libxslt \
			docbook-xml>0:textproc/docbook-xml \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
DOCS_MAKE_ARGS=		DOCDIR=${DOCSDIR} MANDIR=${MANPREFIX}/man/man1
DOCS_ALL_TARGET=	docs
DOCS_PLIST_FILES=	man/man1/compton.1.gz man/man1/compton-trans.1.gz
DOCS_PORTDOCS=		README.md cdbus-driver.sh

post-patch:
# Adjust the location of configuration file
	@${REINPLACE_CMD} -e '/config_system_dir/s|/etc|${LOCALBASE}&|' \
		${WRKSRC}/src/compton.c

.include <bsd.port.mk>
