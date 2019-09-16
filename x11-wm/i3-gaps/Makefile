# $FreeBSD$

PORTNAME=	i3
DISTVERSION=	4.17.1
CATEGORIES=	x11-wm
PKGNAMESUFFIX=	-gaps

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Fork of i3 tiling window manager with more features, including gaps

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libev.so:devel/libev \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libpcre.so:devel/pcre \
		libstartup-notification-1.so:x11/startup-notification \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util \
		libxcb-xrm.so:x11/xcb-util-xrm \
		libxkbcommon.so:x11/libxkbcommon \
		libyajl.so:devel/yajl
RUN_DEPENDS=	p5-AnyEvent-I3>=0:devel/p5-AnyEvent-I3 \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny

USES=		autoreconf compiler:c11 gettext-runtime gmake gnome iconv \
		localbase perl5 pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Airblader
USE_PERL5=	run
USE_GNOME=	glib20
USE_XORG=	xcb

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	i3

OPTIONS_DEFINE=		DOCS

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|print_BUILD_DOCS=yes|print_BUILD_DOCS=no|' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
