# New ports collection makefile for:	qlwm
# Date created:				2000-01-24
# Whom:					trevor
# based on the OpenBSD port by Marc Espie <espie@openbsd.org>
#
# $OpenBSD: Makefile,v 1.2 2000/10/20 12:27:06 espie Exp $
# $FreeBSD$
#

PORTNAME=	qlwm
PORTVERSION=	3.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.alinden.mynetcologne.de/qlwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based window manager

DOCDIR=		share/doc/${PORTNAME}
DOCS=		CHANGES README
LIBDIR=		lib/${PORTNAME}
PLIST=		${WRKDIR}/pkg-plist
MAN1=		qlwm.1
USE_QT_VER=	3
USE_X_PREFIX=	yes
REINPLACE_ARGS=	-i'' -E

MAKE_ENV=	DEST="${PREFIX}/${LIBDIR}" INCPATH="${QTCPPFLAGS}" \
		LIBS="${QTCFGLIBS} -lqt-mt -pthread" LINK="${CXX}" MOC="${MOC}"

post-patch:
	${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} \
		's|/usr/local/qlwm|${PREFIX}/${LIBDIR}|g ; \
		 s|^CXX|#CXX|g ; \
		 s|^INCPATH|#INCPATH|g ; \
		 s|^LFLAGS|#LFLAGS|g ; \
		 s|^LIBS|#LIBS|g ; \
		 s|^LINK|#LINK|g ; \
		 s|^MOC|#MOC|g'

pre-install:
	${ECHO_CMD} bin/qlwm > ${PLIST}
.for i in biff dclock qlwm
	${ECHO_CMD} ${LIBDIR}/$i >> ${PLIST}
.endfor
	for i in `cd ${WRKSRC}/files; ${ECHO_CMD} *`; do \
		${ECHO_CMD} ${LIBDIR}/files/$$i >> ${PLIST}; \
	done
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/$i >> ${PLIST}
.endfor
.endif
.for i in ${LIBDIR}/files ${LIBDIR}
	${ECHO_CMD} @dirrm $i >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${MKDIR} ${PREFIX}/${LIBDIR}/files
	${INSTALL_DATA} ${WRKSRC}/files/* ${PREFIX}/${LIBDIR}/files
	${INSTALL_PROGRAM} ${WRKSRC}/src/qlwm ${WRKSRC}/dclock/dclock \
		${WRKSRC}/mail/biff ${PREFIX}/${LIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${DOCDIR}
.endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/qlwm.1 ${PREFIX}/man/man1
	${SED} -e s,%PREFIX%,${PREFIX},g <${FILESDIR}/qlwm >${WRKSRC}/qlwm
	${INSTALL_SCRIPT} ${WRKSRC}/qlwm ${PREFIX}/bin

.include <bsd.port.mk>
