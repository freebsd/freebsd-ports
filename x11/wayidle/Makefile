PORTNAME=	wayidle
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~whynothugo/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
# XXX Teach USES=cargo to not override default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wait for wayland compositor idle timeouts
WWW=		https://sr.ht/~whynothugo/wayidle

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE.md

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

do-build-MANPAGES-on:
	scdoc < ${WRKSRC}/${PORTNAME}.1.scd >${WRKSRC}/${PORTNAME}.1

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/${MANPAGES_PLIST_FILES:H}

.include <bsd.port.mk>
