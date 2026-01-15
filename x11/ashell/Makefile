PORTNAME=	ashell
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Ready to go Wayland status bar for Hyprland
WWW=		https://malpenzibo.github.io/ashell/

LICENSE=	MIT
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
	@${BSDMAKE} PATCHDIR=${PATCHDIR}/iced WRKSRC=${WRKSRC_crate_iced} \
		do-patch
# https://github.com/RazrFalcon/fontdb/issues/61
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g' \
		${WRKSRC_crate_fontdb-0.18.0}/src/lib.rs \
		${WRKSRC_crate_fontdb-0.23.0}/src/lib.rs
# temporary hack to avoid the following error in configure phase
# error: failed to select a version for the requirement `redox_syscall = "^0.4"`
	@${REINPLACE_CMD} -E '/redox_syscall =/s/0\.4(\.[0-9])?/0\.5/' \
		${WRKSRC_crate_softbuffer}/Cargo.toml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
