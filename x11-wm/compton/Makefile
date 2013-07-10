# $FreeBSD$

PORTNAME=	compton
PORTVERSION=	20130625
CATEGORIES=	x11-wm

MAINTAINER=	femc7488@gmail.com
COMMENT=	Feature-rich compositing window manager for X11

LICENSE=	MIT

LIB_DEPENDS=	config:${PORTSDIR}/devel/libconfig
RUN_DEPENDS=	xprop:${PORTSDIR}/x11/xprop \
		xwininfo:${PORTSDIR}/x11/xwininfo

USE_GITHUB=	yes
GH_ACCOUNT=	chjj
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	b26bbc0

USES=		gmake pkgconfig
USE_XORG=	xcomposite xdamage xrandr xrender

MAKE_ARGS=	COMPTON_VERSION=git-${PORTVERSION}-${GH_COMMIT} \
		XDGDIR=${LOCALBASE}/etc/xdg
ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	PCRE DRM OPENGL DBUS DOCS
OPTIONS_DEFAULT=	PCRE DRM OPENGL DBUS

PCRE_DESC=	Blacklist support (via libpcre)
DRM_DESC=	DRM support
DOCS_DESC=	Build manpages (requires AsciiDoc/DocBook)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.else
MAKE_ARGS+=	NO_REGEX_PCRE=yes
.endif

.if ${PORT_OPTIONS:MDRM}
LIB_DEPENDS+=	drm:${PORTSDIR}/graphics/libdrm
.else
MAKE_ARGS+=	NO_VSYNC_DRM=yes
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		gl
.else
MAKE_ARGS+=	NO_VSYNC_OPENGL=yes
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
.else
MAKE_ARGS+=	NO_DBUS=yes
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	a2x:${PORTSDIR}/textproc/asciidoc \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml-450 \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAKE_ARGS+=	DOCDIR=${DOCSDIR} MANDIR=${MANPREFIX}/man/man1
ALL_TARGET+=	docs
MAN1=		compton.1 compton-trans.1
PORTDOCS=	README.md cdbus-driver.sh
.endif

post-patch:
# Adjust the location of configuration file
	@${REINPLACE_CMD} -e '/config_system_dir/s|/etc|${LOCALBASE}&|' \
		${WRKSRC}/src/compton.c

.include <bsd.port.mk>
