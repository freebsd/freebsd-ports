PORTNAME=	xdtm
PORTVERSION=	2.5.8
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/applications

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Graphical shell for the X Window System

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright

USES=		imake xorg
USE_XORG=	xaw

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
