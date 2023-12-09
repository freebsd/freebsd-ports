PORTNAME=	Xbae
PORTVERSION=	4.60.4
PORTREVISION=	5
CATEGORIES=	x11-toolkits math
MASTER_SITES=	SF
DISTNAME=	xbae-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Motif-based widget which displays a grid of cells as a spreadsheet
WWW=		https://xbae.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool motif
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-production

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
