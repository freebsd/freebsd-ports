PORTNAME=	ashell
DISTVERSION=	0.5.0
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Ready to go Wayland status bar for Hyprland
WWW=		https://malpenzibo.github.io/ashell/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libinotify.so:devel/libinotify \
		libudev.so:devel/libudev-devd \
		libpipewire-0.3.so:multimedia/pipewire \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo llvm localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	MalpenZibo

LDFLAGS+=	-linotify

PORTSCOUT=	limit:^[0-9]\.

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${PATCH} -s -p0 -d ${WRKSRC_crate_iced} < \
		${PATCHDIR}/extra-patch-iced
# https://github.com/RazrFalcon/fontdb/issues/61
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g' \
		${WRKSRC_crate_fontdb-0.18.0}/src/lib.rs \
		${WRKSRC_crate_fontdb-0.23.0}/src/lib.rs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
