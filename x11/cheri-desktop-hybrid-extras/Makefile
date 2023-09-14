PORTNAME=	cheri-desktop-hybrid-extras
PORTVERSION=	20230914
PORTREVISION=	0
CATEGORIES=	x11

MAINTAINER=	konrad.witaszczyk@cl.cam.ac.uk
COMMENT=	Meta-port with hybrid ABI applications for the CHERI desktop environment.
WWW=		https://cheribsd.org/

USES=		metaport

ONLY_FOR_ARCHS=		aarch64
ONLY_FOR_ARCHS_REASON=	requires CheriABI or hybrid ABI www/cheri-desktop only available for arm64

RUN_DEPENDS=	${LOCALBASE}/bin/chrome:www/chromium

.include <bsd.port.mk>
