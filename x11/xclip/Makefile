# Created by: ijliao
# $FreeBSD$

PORTNAME=	xclip
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Interface to X selections ("the clipboard") from the command line

LICENSE=	GPLv2

USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env
USE_XORG=	x11 xmu
USES=	gmake
GNU_CONFIGURE=	yes

MAN1=		xclip.1 xclip-copyfile.1
PLIST_FILES=	bin/xclip bin/xclip-copyfile bin/xclip-cutfile bin/xclip-pastefile

pre-configure:
	@cd ${WRKSRC}; ./bootstrap

post-patch:
	${REINPLACE_CMD} 's,mktemp,mktemp -t xclip,' \
		${WRKSRC}/xclip-copyfile

.include <bsd.port.mk>
