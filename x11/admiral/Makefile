# $FreeBSD$

PORTNAME=	admiral
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-7
DISTVERSIONSUFFIX=	-g5a9f33b
PORTREVISION=	14
CATEGORIES=	x11

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Merge concurrent outputs for a status bar

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sector-f

CARGO_CRATES=	ansi_term-0.10.2 \
		atty-0.2.6 \
		bitflags-1.0.1 \
		clap-2.29.2 \
		libc-0.2.49 \
		num_cpus-1.8.0 \
		quote-0.3.15 \
		redox_syscall-0.1.37 \
		redox_termios-0.1.1 \
		serde-1.0.27 \
		serde_derive-1.0.27 \
		serde_derive_internals-0.19.0 \
		strsim-0.6.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		threadpool-1.7.1 \
		toml-0.4.5 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		vec_map-0.8.0 \
		winapi-0.3.3 \
		winapi-i686-pc-windows-gnu-0.3.2 \
		winapi-x86_64-pc-windows-gnu-0.3.2

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

PLIST_FILES=	bin/admiral

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/admiral

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} admiral.d ${STAGEDIR}${EXAMPLESDIR}/admiral.d)

.include <bsd.port.mk>
