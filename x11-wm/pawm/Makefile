# New ports collection makefile for:	pawm
# Date created:				2002-08-22
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pawm
PORTVERSION=	1.9.7
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.pleyades.net/pawm/files/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	The Puto Amo Window Manager

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2

DOCS=		AUTHORS Changelog GPL INSTALL README THANKS
PLIST=		${WRKDIR}/pkg-plist
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

do-configure:
	cd ${WRKSRC} && \
		bash ./0 --prefix=${PREFIX} --datadir=${PREFIX}/share/pawm

pre-install:
	${ECHO_CMD} bin/pawm > ${PLIST}
	${ECHO_CMD} etc/pawm.conf >> ${PLIST}
	for ii in `${LS} ${WRKSRC}/data/icons`; do \
		${ECHO_CMD} share/pawm/icons/$$ii >> ${PLIST}; \
	done
	${ECHO_CMD} @dirrm share/pawm/icons >> ${PLIST}
	${ECHO_CMD} @dirrm share/pawm >> ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/pawm/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/pawm >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pawm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/conf/pawm.conf ${PREFIX}/etc/
	${MKDIR} ${PREFIX}/share/pawm/icons
	for ii in `${LS} ${WRKSRC}/data/icons/*`; do \
		${INSTALL_DATA} $$ii ${PREFIX}/share/pawm/icons ; \
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
