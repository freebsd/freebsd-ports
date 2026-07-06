PORTNAME=	ashell
DISTVERSION=	0.9.0
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Ready to go Wayland status bar for Hyprland and Niri
WWW=		https://malpenzibo.github.io/ashell/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libudev.so:devel/libudev-devd \
		libpipewire-0.3.so:multimedia/pipewire \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo llvm

USE_GITHUB=	yes
GH_ACCOUNT=	MalpenZibo

PORTSCOUT=	limit:^[0-9]\.

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

# XXX Drop after FreeBSD 14.* EOL around 2028-11-30
# https://cgit.freebsd.org/src/commit/?id=3965de642c29
.if !exists(/usr/include/sys/inotify.h)
LIB_DEPENDS+=	libinotify.so:devel/libinotify
USES+=		localbase:ldflags
LDFLAGS+=	-linotify
.endif

post-patch:
# https://github.com/RazrFalcon/fontdb/issues/61
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g' \
		${WRKSRC_crate_fontdb}/src/lib.rs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
