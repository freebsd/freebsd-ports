PORTNAME=	swayrbar
DISTVERSION=	0.4.2
PORTREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	status_command for swaybar
WWW=		https://sr.ht/~tsdh/swayr/#swayrbar

LICENSE=	GPLv3+
LICENSE_FILE=	${_LICENSE_STORE}/GPLv3

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Respect PREFIX for config
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/bar.rs \
		${WRKSRC}/src/config.rs \
		${WRKSRC}/src/shared/cfg.rs

.include <bsd.port.mk>
