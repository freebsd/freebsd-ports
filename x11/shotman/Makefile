PORTNAME=	shotman
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~whynothugo/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
# XXX Teach USES=cargo to not override default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	https://git.sr.ht/~whynothugo/${PORTNAME}/commit/
PATCHFILES+=	020226f74730.patch:-p1 # manpage

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Uncompromising screenshot GUI for Wayland
WWW=		https://git.sr.ht/~whynothugo/shotman

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE.md

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cargo pkgconfig
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES SLURP
OPTIONS_DEFAULT=MANPAGES SLURP

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

SLURP_DESC=		Interactive region selector
SLURP_RUN_DEPENDS=	slurp:x11/slurp

do-build-MANPAGES-on:
	scdoc < ${WRKSRC}/${PORTNAME}.1.scd >${WRKSRC}/${PORTNAME}.1

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/${MANPAGES_PLIST_FILES:H}

.include <bsd.port.mk>
