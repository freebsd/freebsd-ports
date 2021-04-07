PORTNAME=	i3
DISTVERSION=	4.19.1
PORTREVISION=	1
CATEGORIES=	x11-wm
PKGNAMESUFFIX=	-gaps

PATCH_SITES=	https://github.com/i3/i3/commit/
PATCHFILES=	a7d873f8ccb117c8e0775fe5bfe5804416b89709.patch:-p1

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Fork of i3 tiling window manager with more features, including gaps

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
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

USES=		compiler:c11 gettext-runtime gnome iconv localbase:ldflags \
		meson perl5 pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Airblader
USE_GNOME=	glib20
USE_XORG=	xcb

MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	i3

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc
DOCS_MESON_TRUE=	docs

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
MANPAGES_MESON_TRUE=	mans

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},g' -e 's,/etc,${PREFIX}&,g' \
		${WRKSRC}/man/i3-config-wizard.man \
		${WRKSRC}/man/i3.man

.include <bsd.port.mk>
