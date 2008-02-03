# New ports collection makefile for:	x3270
# Date created:		31 January 1995
# Whom:			janek
#
# $FreeBSD$
#

PORTNAME=	x3270
PORTVERSION=	3.3.7
CATEGORIES=	x11 net
MASTER_SITES=	SFE
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3270 Terminal emulator

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_IMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--without-pr3287 --with-fontdir=local --disable-dbcs
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
