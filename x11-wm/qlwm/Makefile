# New ports collection makefile for:	qlwm
# Date created:				2000-01-24
# Whom:					trevor
# based on the OpenBSD port by Marc Espie <espie@openbsd.org>
#
# $OpenBSD: Makefile,v 1.2 2000/10/20 12:27:06 espie Exp $
# $FreeBSD$
#

PORTNAME=	qlwm
PORTVERSION=	2.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.netcologne.de/~nc-lindenal/qlwm/

MAINTAINER=	trevor@FreeBSD.org

DOCDIR=		share/doc/qlwm
DOCS=		CHANGES README
LIBDIR=		lib/qlwm
PLIST=		${WRKDIR}/pkg-plist
MAN1=		qlwm.1
USE_QT_VER=	2
USE_X_PREFIX=	yes

MAKE_ENV=	LFLAGS="-L${X11BASE}/lib -L${X11BASE}/lib/qt2" \
		QTDIR=${X11BASE} \
		DEST=${PREFIX}/${LIBDIR}

post-patch:
	${PERL} -pi -e "s:/usr/local/qlwm:${PREFIX}/${LIBDIR}:g" ${WRKSRC}/Makefile
	${PERL} -pi -e "s:-lqt:-lqt2:g ; s:bin/moc:bin/moc2:g" \
		${WRKSRC}/*/Makefile

pre-install:
	${ECHO} bin/qlwm > ${PLIST}
.for i in biff dclock qlwm
	${ECHO} ${LIBDIR}/$i >> ${PLIST}
.endfor
	for i in `cd ${WRKSRC}/files; ${ECHO} *`; do \
		${ECHO} ${LIBDIR}/files/$$i >> ${PLIST}; \
	done
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO} ${DOCDIR}/$i >> ${PLIST}
.endfor
.endif
.for i in ${LIBDIR}/files ${LIBDIR}
	${ECHO} @dirrm $i >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
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
