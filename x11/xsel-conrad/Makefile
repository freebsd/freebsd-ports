# Ports collection makefile for:	xsel-conrad
# Date created:		9 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xsel
PORTVERSION=	1.2.0
CATEGORIES=	x11
MASTER_SITES=	http://www.vergenet.net/~conrad/software/xsel/download/ \
		CENKES
PKGNAMESUFFIX=	-conrad

MAINTAINER=	code@apotheon.net
COMMENT=	Access X selection from command line

LICENSE=	xsel-conrad
LICENSE_GROUPS=	COPYFREE
LICENSE_NAME=	xsel-conrad license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

CONFLICTS_INSTALL=	xsel-[0-9]*
USE_XORG=	x11 xext xt xproto ice sm
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXext -lX11
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	ChangeLog README
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|jmp_buf|sigjmp_buf|g' ${WRKSRC}/xsel.c
	@${REINPLACE_CMD} -e 's|@X_CFLAGS@|${CFLAGS}|;\
		s|@X_LIBS@|${LDFLAGS}|' ${WRKSRC}/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1x ${MAN1PREFIX}/man/man1/${PORTNAME}.1
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
