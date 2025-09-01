PORTNAME=	inputplug
DISTVERSION=	0.4.0
PORTREVISION=	36
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	XInput event monitor daemon
WWW=		https://github.com/andrewshadura/inputplug

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo xorg
USE_GITHUB=	yes
GH_ACCOUNT=	andrewshadura
USE_XORG=	x11 xcb xi
CARGO_CRATES=	anyhow-1.0.44 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		cc-1.0.70 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		gethostname-0.2.1 \
		heck-0.3.3 \
		lazy_static-1.4.0 \
		libc-0.2.103 \
		log-0.4.14 \
		memoffset-0.6.4 \
		nix-0.20.2 \
		nix-0.22.2 \
		pidfile-rs-0.1.0 \
		pkg-config-0.3.20 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.29 \
		quote-1.0.9 \
		structopt-0.3.23 \
		structopt-derive-0.4.16 \
		syn-1.0.78 \
		textwrap-0.11.0 \
		thiserror-1.0.29 \
		thiserror-impl-1.0.29 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		version_check-0.9.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-wsapoll-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11rb-0.8.1

PLIST_FILES=	bin/inputplug \
		share/man/man1/inputplug.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
