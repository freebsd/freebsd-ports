PORTNAME=	sirula
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple app launcher for Wayland written in Rust
WWW=		https://github.com/DorianRudolph/sirula

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		cargo gnome
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
GH_ACCOUNT=	DorianRudolph
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Respect PREFIX for system config
	@${REINPLACE_CMD} -e 's,/usr/share,${DATADIR:H},' \
		-e 's,/etc,${PREFIX}&,' \
		${WRKSRC_crate_xdg}/src/lib.rs

.include <bsd.port.mk>
