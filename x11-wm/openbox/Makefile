# New ports collection makefile for:	openbox
# Date created:				2002-04-28
# Whom:					trevor
# based on the blackbox port
#
# $FreeBSD$
#

PORTNAME=	openbox
PORTVERSION=	0.3.0.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://icculus.org/openbox/releases/
DISTNAME=	openbox-3.0-beta1

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Derived from, and similar to, Blackbox

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/Xft

DOCS=		ABOUT-NLS AUTHORS COPYING ChangeLog README TODO
THEMES=		allegro artwiz blah41 om4ob thebear
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
#USE_AUTOMAKE=	yes

do-patch:
	${CP} -P ${WRKSRC}/data/rc.xml ${WRKSRC}/data/rc.xml.orig
	${CP} -P ${WRKSRC}/data/menu.xml ${WRKSRC}/data/openbox-menu.xml
	${SED} -E "s:/etc/X11/openbox/:${PREFIX}/share/openbox/:g" \
		< ${WRKSRC}/data/rc.xml.orig > ${WRKSRC}/data/rc.xml
	${RM} ${WRKSRC}/data/rc.xml.orig

pre-configure:
	${MKDIR} ${WRKDIR}
	${ECHO_CMD} \
	"Warning:  source code for this version has not been reviewed!" \
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} 
	@${ECHO_CMD} Waiting ten seconds--press control-C to cancel build.
	@sleep 10

pre-install:
	${RM} -f ${PLIST}
.for ii in openbox  kdetrayproxy obconf
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
	cd ${WRKSRC} && ${FIND} -s data themes -type f \
		| ${SED} -e 's:^:share/openbox/:' >> ${PLIST} \
		&& ${FIND} data themes -type d | sort -r \
		| ${SED} -e 's:^:@dirrm share/openbox/:' >> ${PLIST}
	cd ${WRKSRC}/data && ${FIND} -s * -type f \
		| ${SED} -e 's:^:share/openbox/:' >> ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/openbox/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/openbox >> ${PLIST}
.endif

do-install:
	${MKDIR} ${PREFIX}/share/openbox
.for ii in openbox/.libs/openbox tools/kdetrayproxy/kdetrayproxy \
	tools/obconf/.libs/obconf
	${INSTALL_PROGRAM} ${WRKSRC}/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/tools/themeupdate/themeupdate.py \
		${PREFIX}/bin
	cd ${WRKSRC} && pax -r -w data themes ${PREFIX}/share/openbox/
	cd ${WRKSRC} && ${INSTALL_DATA} data/* ${PREFIX}/share/openbox/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
