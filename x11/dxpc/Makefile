# Created by: Bruce A. Mah <bmah@ca.sandia.gov>
# $FreeBSD$

PORTNAME=	dxpc
PORTVERSION=	3.9.2
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compressing X protocol proxy designed to support X11 over slow links

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

LICENSE=	BSD2CLAUSE

USE_XORG=	x11
USES=		gmake tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo-lib=${LOCALBASE}
MAKE_ARGS=	INSTALL="${INSTALL_PROGRAM}" \
		bindir=${STAGEDIR}${PREFIX}/bin \
		man1dir=${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/dxpc \
		man/man1/dxpc.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-R$$withval/lib||' ${WRKSRC}/configure

.include <bsd.port.mk>
