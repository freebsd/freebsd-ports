PORTNAME=	swayr
DISTVERSION=	0.28.1
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Urgent-first/LRU window switcher for sway
WWW=		https://sr.ht/~tsdh/swayr/#swayr

LICENSE=	GPLv3+
LICENSE_FILE=	${_LICENSE_STORE}/GPLv3

USES=		cargo
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}d

post-patch:
# Respect PREFIX for config and icons
	@${REINPLACE_CMD} -e 's,/usr/share,${DATADIR:H},' \
		-e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/config.rs \
		${WRKSRC}/src/shared/cfg.rs \
		${WRKSRC}/src/util.rs

.include <bsd.port.mk>
