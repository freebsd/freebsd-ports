# New ports collection makefile for:	x3270
# Date created:		31 January 1995
# Whom:			janek
#
# $FreeBSD$
#

PORTNAME=	x3270
PORTVERSION=	3.3.10
CATEGORIES=	x11 net
MASTER_SITES=	http://x3270.bgp.nu/download/
EXTRACT_SUFX=	ga5-src.tgz

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	3270 Terminal emulator

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_IMAKE=	yes
USE_ICONV=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-pr3287 --with-fontdir=local --disable-dbcs
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib" \
		LIBS="-L${PREFIX}/lib"
.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USE_OPENSSL=	yes
.endif
MAKE_ARGS+=	COMPRESSMANCMD="${DO_NADA}" \
		INSTALL="${INSTALL}" INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP} ${_BINOWNGRP} -m ${BINMODE}" \
		INSTBINFLAGS="${_BINOWNGRP} -m ${BINMODE}" \
		INSTDATFLAGS="${_SHROWNGRP} -m ${SHAREMODE}" \
		INSTMANFLAGS="${_MANOWNGRP} -m ${MANMODE}"

WRKSRC=		${WRKDIR}/x3270-${PORTVERSION:R}
MAN1=		x3270.1 x3270if.1 x3270-script.1
MAN5=		ibm_hosts.5
MANCOMPRESSED=	no

post-patch:
	${REINPLACE_CMD} -e 's|\$$(INSTALL) -c|$$(INSTALL) $$(INSTALLFLAGS)|g' \
		${WRKSRC}/Imakefile.in

.include <bsd.port.mk>
