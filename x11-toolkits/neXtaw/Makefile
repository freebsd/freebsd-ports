# New ports collection makefile for:	neXtaw
# Version required:	0.5.1
# Date created:		16 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	neXtaw-0.5.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://people.FreeBSD.org/~tg/		
EXTRACT_SUFX=	.tar.gz.bin

MAINTAINER=	tg@FreeBSD.org

USE_IMAKE=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -rf ${WRKSRC}/X11

post-configure:
	@${ECHO_MSG} "*********************************************************************"
	@${ECHO_MSG} "* Don't worry about the warning messages above, the port will build *"
	@${ECHO_MSG} "*********************************************************************"
	@cd ${WRKSRC}/exports/include/X11/neXtaw; ${LN} -sf ../../../../*.h .

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/neXtaw
	${INSTALL_DATA} ${WRKSRC}/README.neXtaw ${PREFIX}/share/doc/neXtaw
.endif
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libneXtaw.so.6.1 ${PREFIX}/lib/libneXtaw.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
