# New ports collection makefile for:	openbox
# Date created:				2002-04-28
# Whom:					trevor
# based on the blackbox port
#
# $FreeBSD$
#

PORTNAME=	openbox
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Derived from, and similar to, Blackbox

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/Xft

CONFIGURE_ARGS=	--datadir=${PREFIX}/share/openbox --prefix=${PREFIX} \
		--sysconfdir=${PREFIX}/etc/openbox
DOCS=		ABOUT-NLS AUTHORS CHANGELOG COPYING README TODO
GNU_CONFIGURE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_GNOME=	glib20 libxml2
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

post-build:
	cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt -c -o ja.mo ja.po
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
.for ii in gnome-panel-control openbox kdetrayproxy themeupdate.py
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
.for ii in parser render
	${ECHO_CMD} libdata/pkgconfig/ob${ii}-3.0.pc >> ${PLIST}
.endfor
	cd ${WRKSRC} && ${FIND} -s data themes -type f \
		| ${SED} -e 's:^:share/openbox/:' >> ${PLIST} \
		&& ${FIND} data themes -type d | sort -r \
		| ${SED} -e 's:^:@dirrm share/openbox/:' >> ${PLIST}
	cd ${WRKSRC}/data && ${FIND} -s * -type f \
		| ${SED} -e 's:^:share/openbox/:' >> ${PLIST}
	${ECHO_CMD} share/gnome/wm-properties/openbox.desktop >> ${PLIST}
	${ECHO_CMD} share/locale/ja/LC_MESSAGES/openbox.mo >> ${PLIST}
.for ii in menu rc
	${ECHO_CMD} etc/openbox/xdg/openbox/${ii}.xml >> ${PLIST}
.endfor
.for ii in parse.h render.h theme.h version.h
	${ECHO_CMD} include/openbox/${ii} >> ${PLIST}
.endfor
.for ii in openbox/xdg/openbox openbox/xdg openbox
	${ECHO_CMD} @dirrm etc/${ii} >> ${PLIST}
.endfor
.for ii in la lai so so.2
	${ECHO_CMD} lib/libobparser.${ii} >> ${PLIST}
	${ECHO_CMD} lib/libobrender.${ii} >> ${PLIST}
.endfor
.for ii in gnome/wm-properties gnome
	${ECHO_CMD} "@unexec rmdir %D/share/${ii} 2>/dev/null || true" \
		>> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/openbox/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/openbox >> ${PLIST}
.endif
.for ii in include share 
	${ECHO_CMD} @dirrm ${ii}/openbox >> ${PLIST}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/po/ja.mo \
		${PREFIX}/share/locale/ja/LC_MESSAGES/openbox.mo
	${MKDIR} ${DATADIR} ${PREFIX}/share/gnome/wm-properties \
		${PREFIX}/etc/openbox/xdg/openbox ${PREFIX}/include/openbox
.for ii in parser/parse render/theme render/render version
	${INSTALL_DATA} ${WRKSRC}/${ii}.h ${PREFIX}/include/openbox/
.endfor
.for ii in parser render
	${INSTALL_DATA} ${WRKSRC}/${ii}/ob${ii}-3.0.pc \
		${PREFIX}/libdata/pkgconfig/
.endfor
.for ii in menu rc
	${INSTALL_DATA} ${WRKSRC}/data/${ii}.xml \
		${PREFIX}/etc/openbox/xdg/openbox
.endfor
.for ii in openbox/.libs/openbox tools/kdetrayproxy/kdetrayproxy \
	tools/gnome-panel-control/gnome-panel-control
	${INSTALL_PROGRAM} ${WRKSRC}/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/tools/themeupdate/themeupdate.py \
		${PREFIX}/bin
	cd ${WRKSRC} && ${PAX} -r -w data themes ${PREFIX}/share/openbox/
	cd ${WRKSRC} && ${INSTALL_DATA} data/* ${PREFIX}/share/openbox/
	cd ${WRKSRC} && ${INSTALL_DATA} data/openbox.desktop \
		${PREFIX}/share/gnome/wm-properties/
.for ii in la lai so so.2
	cd ${WRKSRC} && \
		${INSTALL_DATA} parser/.libs/libobparser.${ii} ${PREFIX}/lib \
		&& ${INSTALL_DATA} render/.libs/libobrender.${ii} ${PREFIX}/lib
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
