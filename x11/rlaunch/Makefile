PORTNAME=	rlaunch
DISTVERSION=	1.3.14
PORTREVISION=	19
CATEGORIES=	x11

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, light-weight and modern application launcher for X11
WWW=		https://github.com/PonasKovas/rlaunch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails, see https://github.com/PonasKovas/rlaunch/issues/16

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	PonasKovas

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		clap-2.33.0 \
		fuzzy-matcher-0.3.7 \
		heck-0.3.1 \
		hermit-abi-0.1.6 \
		lazy_static-1.4.0 \
		libc-0.2.66 \
		maybe-uninit-2.0.0 \
		once_cell-1.7.2 \
		pkg-config-0.3.17 \
		proc-macro-error-0.4.8 \
		proc-macro-error-attr-0.4.8 \
		proc-macro2-1.0.8 \
		quote-1.0.2 \
		rustversion-1.0.2 \
		strsim-0.8.0 \
		structopt-0.3.9 \
		structopt-derive-0.4.2 \
		syn-1.0.14 \
		syn-mid-0.5.0 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-dl-2.18.5

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
