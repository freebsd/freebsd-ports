# New ports collection makefile for:	badwm
# Date created:				2002-10-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	badwm
PORTVERSION=	0.1.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/BadWM/BadWM-${PORTVERSION}
DISTNAME=	BadWM-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager based on evilwm

USE_XORG=	x11 ice sm xext
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		BadWM.1
MAN5=		BadWMrc.5
MLINKS=		BadWM.1 badwm.1 \
		BadWMrc.5 badwmrc.5
PORTDOCS=	${DOCS}
PLIST_FILES=	bin/BadWM bin/badwm

DOCS=		AUTHORS ChangeLog INSTALL LICENSE README THANKS TODO

post-patch:
	@${REINPLACE_CMD} -e 's|<getopt\.h>|<unistd.h>|g' ${WRKSRC}/src/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/BadWM ${PREFIX}/bin
	${LN} -sf BadWM ${PREFIX}/bin/badwm
	${INSTALL_MAN} ${WRKSRC}/man/BadWM.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/BadWMrc.5 ${MAN5PREFIX}/man/man5
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
